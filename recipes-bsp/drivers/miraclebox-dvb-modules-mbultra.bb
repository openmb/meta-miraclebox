KV = "3.14.2"
SRCDATE = "20160121"

SRC_URI[md5sum] = "3919231c1ee6ad231c5bc75ffca37b2f"
SRC_URI[sha256sum] = "242028aa90ace81b62d50ca115801c5d276d8aba6291eb7544831aabaabb60c9"

SRC_URI = "http://source.mynonpublic.com/ini/ini-800-drivers-${KV}-${SRCDATE}.zip"

require miraclebox-dvb-modules.inc
