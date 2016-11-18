#! /bin/bash

####  Fixup $APPNAME.desktop.
APPNAME=HeartFEniCSUI
ICONNAME=logo/heart-logo-jeanette.png

cd $(dirname "$0")
APPDIR="$PWD"
EXEC="$APPDIR/$APPNAME"
ICON="$APPDIR/$ICONNAME"
Path="$APPDIR/"

sed -i -e "s@^Icon=.*@Icon=$ICON@" \
    -e "s@^Exec.*@Exec=$EXEC@"  \
    -e "s@^Path.*@Path=$Path@" "$APPNAME.desktop"
    
   
##############################################################################
# Installing the Desktop FILES

cd ${APPDIR}; desktop-file-install ${APPNAME}.desktop --dir=$HOME/.local/share/applications/




  


