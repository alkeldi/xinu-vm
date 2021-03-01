FROM gcc:latest

# install extra build tools tools
RUN apt-get clean -y\
    && apt-get update -y\
    && apt-get upgrade -y\
    && apt-get upgrade -y\
    && apt-get install flex bison gawk -y\
    && ln -s /usr/local/bin/gcc /usr/bin/gcc\
    && mkdir -p /srv/tftp

ENTRYPOINT ["/bin/sleep", "infinity"]
