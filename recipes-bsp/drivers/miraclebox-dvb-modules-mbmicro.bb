SSUMMARY = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"

KV = "4.0.1"
SRCDATE = "20161124"

PV = "${KV}+${SRCDATE}"
PR = "r0"

SRC_URI[md5sum] = "76bb3a95f4acb182d91269fc3d583746"
SRC_URI[sha256sum] = "28c2f4aa74e2022903a8db4358bd7bfcd5c8c4f1d0b290d399799bac6a09e39b"

#SRC_URI = "file://ceryon-7000s-dvbdrive-${SRCDATE}.zip"
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
