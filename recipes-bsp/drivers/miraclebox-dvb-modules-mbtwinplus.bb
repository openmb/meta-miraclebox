SUMMARY = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"

KV = "4.1.15"
GCCREV = "4.9.2"
SRCDATE = "20160218"

SRC_URI[md5sum] = "f6ee3e7dfd37a46b5906840eb99e6d49"
SRC_URI[sha256sum] = "3e54438d391ba5d22be5f2f8837368c93d1fa16acf63b2103135cce90723c1c7"

PV = "${KV}+${SRCDATE}"
PR = "r0"

SRC_URI = "http://source.mynonpublic.com/broadmedia/twinplus-drivers-${KV}-${GCCREV}-${SRCDATE}.zip"

S = "${WORKDIR}"

INHIBIT_PACKAGE_STRIP = "1"

inherit module

do_compile() {
}

do_install() {
    install -d ${D}/lib/modules/${KV}/extra
    install -d ${D}/${sysconfdir}/modules-load.d
    install -m 0755 ${WORKDIR}/linuxtv.ko ${D}/lib/modules/${KV}/extra
    echo linuxtv >> ${D}/${sysconfdir}/modules-load.d/_${MACHINE}.conf
}

FILES_${PN} += "${sysconfdir}/modules-load.d/_${MACHINE}.conf"

