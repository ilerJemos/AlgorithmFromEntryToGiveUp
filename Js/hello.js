var http = require('http');
var dt = require('./myfirstmodule');
var url = require('url');
var fs = require("fs");

http.createServer(function (req, res) {
    // res.writeHead(200, {'Content-Type': 'text/html'});
    //res.write("now:"+dt.myDateTime()+"\n");
    // res.end('Hello Wordld!');
    // res.write(req.url);
    // var q = url.parse(req.url,true).query;
    // var txt = q.year+" "+q.month;

    fs.readFile('demofile1.html',function(err,data){
        res.writeHead(200, {'Content-Type': 'text/html'});
        res.write(data);
        res.end;
    })
    // res.end(txt)
}).listen(8080);


http.createServer(function(req,res){
    var q= url.parse(req.url,true)
    var filename = "."+q.pathname+".html"
    fs.readFile(filename,function(err,data){
        if(err){
            res.writeHead(404,{'Content-Type':"text/html"})
            return res.end("404 not found")
        }
        res.writeHead(200,{'Content-Type':'text/html'})
        res.write(data)
        return res.end()
    })
}).listen(8090)