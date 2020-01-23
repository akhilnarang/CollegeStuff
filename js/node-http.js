import fs from 'fs'
import http from 'http'

http.createServer((_req, res) => {
    fs.readFile("hello-node.js", (err, data) => {
        if (err) throw err
        res.writeHead(200, { "Content-Type": "text/html" })
        res.write("These are the contents of 'hello-node.js'<br>")
        res.write(data)
        res.end()
    })
}).listen(5000)