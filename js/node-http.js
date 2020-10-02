const http = require('http');
import http from 'http'	const fs = require('fs');

const path = require('path');
http.createServer((_req, res) => {	
    fs.readFile("hello-node.js", (err, data) => {	const hostname = 'localhost';
        if (err) throw err	const port = 3000;
        res.writeHead(200, { "Content-Type": "text/html" })	
        res.write("These are the contents of 'hello-node.js'<br>")	const server = http.createServer((req, res) => {
        res.write(data)	    console.log(`Request for ${req.url} by method ${req.method}`);
        res.end()	
    })	    var fileUrl;
}).listen(5000) 	    if (req.url == '/') {
        fileUrl = '/index.html';
    } else {
        fileUrl = req.url;
    }

    if (req.method == 'GET') {

        var filePath = path.resolve('./public' + fileUrl);
        const fileExt = path.extname(filePath);
        if (fileExt == '.html') {
            fs.exists(filePath, exists => {
                if (!exists) {
                    res.statusCode = 404;
                    res.setHeader('Content-Type', 'text/html');
                    res.end(`<html><body><h1>Error 404: ${fileUrl} not found</h1></body></html>`);
                    return;
                }
                res.statusCode = 200;
                res.setHeader('Content-Type', 'text/html');
                fs.createReadStream(filePath).pipe(res);
            });
        } else {
            res.statusCode = 404;
            res.setHeader('Content-Type', 'text/html');
            res.end(`<html><body><h1>Error 404: ${fileUrl} not an HTML file</h1></body></html>`);
            return;
        }
    } else {
        res.statusCode = 404;
        res.setHeader('Content-Type', 'text/html');
        res.end(`<html><body><h1>Error 404: ${fileUrl} not supported (${req.method} is not coded yet)</h1></body></html>`);
        return;
    }
});

server.listen(port, hostname, () => {
    console.log(`Server running at http://${hostname}:${port}`);
});
