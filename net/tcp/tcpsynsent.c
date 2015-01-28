/* tcpsynsent.c  -  tcpsynsent */

#include <xinu.h>

/*------------------------------------------------------------------------
 *  tcpsynsent  -  Handle an incoming segment in the SYN-SENT state
 *------------------------------------------------------------------------
 */
int32	tcpsynsent(
	  struct tcb	*tcbptr,	/* Ptr to a TCB			*/
	  struct netpacket *pkt		/* Ptr to a packet		*/
	)
{
	/* Must receive a SYN or reset connection */

	if (!(pkt->net_tcpcode & TCPF_SYN)) {
		tcpreset (pkt);
		return SYSERR;
	}

	/* Move to SYN-RECEIVED state */

	tcbptr->tcb_state = TCB_SYNRCVD;

	/* Set up parameters, such as the window size */

	tcbptr->tcb_rnext = tcbptr->tcb_rbseq = ++pkt->net_tcpseq;
	tcbptr->tcb_rwnd = tcbptr->tcb_ssthresh = pkt->net_tcpwindow;
	pkt->net_tcpcode &= ~TCPF_SYN;

	/* Send an ACK */

	tcpdata (tcbptr, pkt);
	tcpack (tcbptr, TRUE);

	return OK;
}
