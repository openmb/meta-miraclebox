SSUMMARY = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"

KV = "4.0.1"
SRCDATE = "20160428"

PV = "${KV}+${SRCDATE}"
PR = "r0"

SRC_URI[md5sum] = "470afe9548ab588f98fb24b5387b271c"
SRC_URI[sha256sum] = "558d736cbf432ebff762f4e1b4832110357b26f6dc3ea429f4429ab70075dbf2"

SRC_URI = "http://source.mynonpublic.com/ceryon/ceryon-7000s-dvbdrive-${SRCDATE}.zip"

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
