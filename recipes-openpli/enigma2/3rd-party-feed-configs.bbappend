do_compile_append() {
    [ ! -d ${S}/${sysconfdir}/opkg ] && mkdir -p ${S}/${sysconfdir}/opkg
    echo "src/gz openpli-3rd-party2 http://downloads.pli-images.org/feeds/openpli-4/3rd-party" > ${S}/${sysconfdir}/opkg/3rd-party2-feed.conf
    echo "src/gz openpli-3rd-party-et10000 http://downloads.pli-images.org/feeds/openpli-4/3rd-party-et10000" > ${S}/${sysconfdir}/opkg/3rd-party3-feed.conf
    echo "src/gz openpli-3rdparty http://feeds2.mynonpublic.com/5.1/g300/3rdparty" > ${S}/${sysconfdir}/opkg/3rdparty-feed.conf
}
