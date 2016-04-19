SUMMARY = "Hardware drivers for ${MACHINE}"
SECTION = "base"
PRIORITY = "required"
LICENSE = "CLOSED"

KV = "4.1.15"
GCCREV = "5.3.0"
SRCDATE = "20160419"

SRC_URI[md5sum] = "20eba1f34e0940d46fbd98edeea32f50"
SRC_URI[sha256sum] = "a94b147a24922c738d9b4aa00a8aa851371da26359f8b01ce6d4084a7f6f6ad1"

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

