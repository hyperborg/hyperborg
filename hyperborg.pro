TEMPLATE=subdirs

SUBDIRS+= node \

linux {

SUBDIRS+= plugins/onewire \
          plugins/hhc_n8i8op \
          plugins/paradox \
          plugins/hue \
          plugins/ws3500 \
          plugins/panasonic\
}
