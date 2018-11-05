// ReuqireJS
// main.js
if(!window.jsVer){
    window.jsVer="1.0";
}
window.proj={}
proj.prefix ="prefix";
require .conf({
    path:
    {
        'jquery':'path',
        'cookie':'path',
        'dict':'dict'
    },
    shim:
    {
        'map-ext':{
            deps:['jquery']
        }
    },
    urlArgs:window.urlArgsFun
});
require([document.body.id,'tools'],function(page,tools){
    tools.setAjaxGlobal();
    if(page && page.init){
        window.page=page;
        page.init();
    }
});