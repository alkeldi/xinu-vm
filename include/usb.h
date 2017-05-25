/* usb.h - USB related definitions */

#pragma pack(1)

#define	USB_DVRQ_RT_H2D		0x00
#define	USB_DVRQ_RT_D2H		0x80
#define	USB_DVRQ_RT_DEV		0x00
#define	USB_DVRQ_RT_INTF	0x01
#define	USB_DVRQ_RT_EP		0x00

#define	USB_DVRQ_GET_STS	0
#define	USB_DVRQ_CLR_FEAT	1
#define	USB_DVRQ_SET_FEAT	3
#define	USB_DVRQ_SET_ADDR	5
#define	USB_DVRQ_GET_DESC	6
#define	USB_DVRQ_SET_DESC	7
#define	USB_DVRQ_GET_CFG	8
#define	USB_DVRQ_SET_CFG	9
#define	USB_DVRQ_GET_INTF	10
#define	USB_DVRQ_SET_INTF	11
#define	USB_DVRQ_SYNC_FRM	12

struct	usb_devreq {
	byte	reqtype;	/* Request type		*/
	byte	request;	/* Reqeust		*/
	uint16	value;		/* Specific to request	*/
	uint16	index;		/* Specific to request	*/
	uint16	length;		/* #bytes in data stage	*/
};

struct	usb_devdesc {
	byte	length;		/* Size in bytes	*/
	byte	desctype;	/* Descriptor type	*/
	uint16	bcdusb;		/* USB Spec release	*/
	byte	devclass;	/* Device class		*/
	byte	devsubclass;	/* Device sub-class	*/
	byte	devproto;	/* Protocol code	*/
	byte	maxpktsiz0;	/* Max. pkt size EP 0	*/
	uint16	vendid;		/* Vendor ID		*/
	uint16	prodid;		/* Product ID		*/
	uint16	bcddev;		/* Device release num	*/
	byte	mfgstr;		/* Manufacturer string	*/
	byte	prodstr;	/* Product string	*/
	byte	sernostr;	/* Serial number string	*/
	byte	numcfg;		/* No. of configurations*/
};

struct	usb_cfgdesc {
	byte	length;		/* Size in bytes	*/
	byte	desctype;	/* Descriptor type	*/
	uint16	totallen;	/* Total bytes returned	*/
	byte	numintf;	/* No. of interfaces	*/
	byte	cfgvalue;	/* Configuration value	*/
	byte	cfgstr;		/* Configuration string	*/
	byte	attr;		/* Attributes		*/
	byte	maxpwr;		/* Max power consumption*/
};

struct	usb_intfdesc {
	byte	length;		/* Size in bytes	*/
	byte	desctype;	/* Descriptor type	*/
	byte	intfnum;	/* Interface number	*/
	byte	altsetting;	/* Alternate setting	*/
	byte	numep;		/* No. of endpoints	*/
	byte	intfclass;	/* Interface class	*/
	byte	intfsubclass;	/* Interface sub-class	*/
	byte	intfproto;	/* Protocol code	*/
	byte	intfstr;	/* Interface string	*/
};

struct	usb_epdesc {
	byte	length;		/* Size in bytes	*/
	byte	desctype;	/* Descriptor type	*/
	byte	epaddr;		/* Endpoint address	*/
	byte	attr;		/* Attributes		*/
	uint16	maxpktsize;	/* Max packet size	*/
	byte	interval;	/* Polling interval	*/
};

#pragma pack()

#define	USBD_HCI_EHCI		0

#define	USBD_STATE_DFLT		0
#define	USBD_STATE_ADDR		1
#define	USBD_STATE_CFG		2

#define	NUSBD			1

struct	usbdcblk {
	byte	hcitype;	/* Host controller type	*/
	did32	hcidev;		/* Host contr. device	*/
	byte	address;	/* Device address	*/
	byte	state;		/* Device state		*/
};

extern	struct usbdcblk usbdtab[NUSBD];

#define	USB_CTRL_TRANSFER	0

#define	USB_TFR_EP_CTRL		0
#define	USB_TFR_EP_BULK		1
#define	USB_TFR_EP_INTR		2
#define	USB_TFR_EP_ISO		4

struct	usbtransfer {
	struct	usbdcblk *usbdptr;/* USB device ctl blk	*/
	byte	eptype;		/* Endpoint type	*/
	byte	ep;		/* Endpoint number	*/
	bool8	dirin;		/* Endpoint direction	*/
	struct	usb_devreq *dvrq;/* USB device request	*/
	char	*buffer;	/* Data buffer		*/
	int32	size;		/* Data buffer size	*/
};
