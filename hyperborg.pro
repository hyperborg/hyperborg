TEMPLATE=subdirs

SUBDIRS+= node \

linux {

SUBDIRS+= plugins/onewire \
          plugins/hyi2c \
          plugins/hhc_n8i8op \
          plugins/paradox \
          plugins/hue \
}
