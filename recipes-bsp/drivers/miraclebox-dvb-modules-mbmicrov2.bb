SSUMMARY = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"

KV = "4.0.1"
SRCDATE = "20161213"

PV = "${KV}+${SRCDATE}"
PR = "r0"

SRC_URI[md5sum] = "31cd371b829a6174bd2100de7f8c85d7"
SRC_URI[sha256sum] = "3c46607ad6572268dc02a551c79e669e7a3f2af9d0698b330b2eecaecf4b83c6"

SRC_URI = "http://source.mynonpublic.com/ceryon/ceryon-7005s-dvbdrive-${SRCDATE}.zip"

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

inherit module

do_compile() {
}

do_install() {
    install -d ${D}/lib/modules/${KV}/extra
    install -d ${D}/${sysconfdir}/modules-load.d
    echo "dvbdrive" >> ${D}/${sysconfdir}/modules-load.d/dvbdrive.conf
    install -m 0755 ${WORKDIR}/dvbdrive.ko ${D}/lib/modules/${KV}/extra
    install -d ${D}/etc/rcS.d
}

FILES_${PN} += "${sysconfdir}/modules-load.d/dvbdrive.conf"
