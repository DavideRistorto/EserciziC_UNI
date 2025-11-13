var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Bella' });
});

// route con path specifico /hello
router.get('/hello', function (req, res) {
 res.send('I received a request on /hello!')
}) 

// parametro dinamico
router.get('/products/:id', (req, res) => {
 const productId = req.params.id; // Access the dynamic parameter
 res.send(`Product ID: ${productId}`);
}); 

// gestire richiesta POST
router.post('/', function (req, res) {
 res.send('Got a POST request');
})

// gestire qualsiasi tipo di richiesta (POST, GET, PUT, DELETE, ecc.)
router.all('/any', function (req, res, next) {
 res.send('Got a request with the method ' + req.method);
})

//curl -X POST http://localhost:3000/user/ -d "name=Davide&surname=Rossi"
router.post('/user/', function (req, res) {
 var queryData = req.body; // per POST
  res.writeHead(200, {"Content-Type": "text/plain"}); // impostare header di risposta
 if(queryData){
    res.end("Ciao " + queryData.name + " " + queryData.surname);
 } else {
    res.end("Ciao utente anonimo");
 }  
})

module.exports = router;
