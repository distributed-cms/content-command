# TODO create smarter script to accept arguments and if they are not set, then use following vars as defaults.
export CMD_PORT=50000

sudo docker run -p $CMD_PORT:5000 -d carlosvin/content-command
