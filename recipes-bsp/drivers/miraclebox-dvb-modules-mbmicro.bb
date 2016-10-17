SSUMMARY = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"

KV = "4.0.1"
SRCDATE = "20161014"

PV = "${KV}+${SRCDATE}"
PR = "r0"

SRC_URI[md5sum] = "3ae556555eae03369adcc7e006e81d0f"
SRC_URI[sha256sum] = "98be6f2197c633a105cf89f6fb3fe76e8016c6e343ce32f1877fcdb48b01c3ba"

SRC_URI = "file://ceryon-7000s-dvbdrive-${SRCDATE}.zip"
#SRC_URI = "http://source.mynonpublic.com/ceryon/ceryon-7000s-dvbdrive-${SRCDATE}.zip"

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
