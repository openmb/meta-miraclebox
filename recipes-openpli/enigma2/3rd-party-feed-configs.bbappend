do_compile_append() {
    [ ! -d ${S}/${sysconfdir}/opkg ] && mkdir -p ${S}/${sysconfdir}/opkg
    echo "src/gz openpli-3rdpartyatv http://feeds2.mynonpublic.com/5.3/g300/3rdparty" > ${S}/${sysconfdir}/opkg/3rdpartyatv-feed.conf
}
