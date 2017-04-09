function lazyLoadImg() {
    //common
    function tagName(tagName) {
        return document.getElementsByTagName(tagName);
    }

    function $(id) {
        return document.getElementById(id);
    }

    function addEvent(obj, type, func) {
        if (obj.addEventListener) {
            obj.addEventListener(type, func, false);
        } else if (obj.attachEvent) {
            obj.attachEvent('on' + type, func);
        }
    }
    //这里可以按照需要配置些参数
    var v = {
            eleGroup: null,
            eleTop: null,
            eleHeight: null,
            screenHeight: null,
            visibleHeight: null,
            scrollHeight: null,
            scrolloverHeight: null,
            limitHeight: null
        }
        //对数据进行初始化
    function init(element) {
        v.eleGroup = tagName(element)
        screenHeight = document.documentElement.clientHeight;
        scrolloverHeight = document.body.scrollTop;
        for (var i = 0, j = v.eleGroup.length; i < j; i++) {
            if (v.eleGroup[i].offsetTop <= screenHeight && v.eleGroup[i].getAttribute('data-url')) {
                v.eleGroup[i].setAttribute('src', v.eleGroup[i].getAttribute('data-url'));
                v.eleGroup[i].removeAttribute('data-url')
            }
        }
    }

    function lazyLoad() {
        if (document.body.scrollTop == 0) {
            limitHeight = document.documentElement.scrollTop + document.documentElement.clientHeight;
        } else {
            limitHeight = document.body.scrollTop + document.documentElement.clientHeight;
        }
        for (var i = 0, j = v.eleGroup.length; i < j; i++) {
            if (v.eleGroup[i].offsetTop <= limitHeight && v.eleGroup[i].getAttribute('data-url')) {
                v.eleGroup[i].src = v.eleGroup[i].getAttribute('data-url');
                v.eleGroup[i].removeAttribute('data-url')
            }
        }
    }
    init('img')
    addEvent(window, 'scroll', lazyLoad);
}
