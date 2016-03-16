SUMMARY = "Utilities for transponder dvb-c and dvb-s blindscan"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"

PACKAGES = "miraclebox-blindscan-dvbs-utils-${MACHINE} miraclebox-blindscan-dvbc-utils-${MACHINE}"

PROVIDES += "virtual/blindscan-dvbs virtual/blindscan-dvbc"
RPROVIDES_miraclebox-blindscan-dvbs-utils-${MACHINE} += "virtual/blindscan-dvbs"
RPROVIDES_miraclebox-blindscan-dvbc-utils-${MACHINE} += "virtual/blindscan-dvbc"

SRC_URI = "file://tda1002x file://ini_blindscan"

PV = "2.1"
PR = "r3"

S = "${WORKDIR}/"

do_install() {
    install -d ${D}/${bindir}/
    install -m 0755 "${S}/tda1002x" "${D}/${bindir}"
    install -m 0755 "${S}/ini_blindscan" "${D}/${bindir}"
}

FILES_miraclebox-blindscan-dvbs-utils-${MACHINE} = "${bindir}/*_blindscan"
FILES_miraclebox-blindscan-dvbc-utils-${MACHINE} = "${bindir}/tda1002x"
FILES_miraclebox-blindscan-dvbs-utils-${MACHINE}-dbg = "${bindir}/.debug/*_blindscan"
FILES_miraclebox-blindscan-dvbc-utils-${MACHINE}-dbg = "${bindir}/.debug/tda1002x"

INHIBIT_PACKAGE_STRIP = "1"

PACKAGE_ARCH := "${MACHINE_ARCH}"

