const express = require('express');
const router = express.Router();
const tili = require('../models/tili_model');

router.get('/',
    function (request, response) {
        tili.getAll(function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                console.log(dbResult);
                response.json(dbResult);
            }
        })
    });

router.get('/:id?',
    function (request, response) {
        tili.getById(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult);  
            }
        })
    });


router.post('/', 
function(request, response) {
  tili.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  tili.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  tili.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


//Tästä uusi

router.post('/withdraw', 
function(request, response) {
  tili.withdraw(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      if (dbResult["affectedRows"] > 0) { // affectedRows = 1 if updating row was successful
        console.log("Success!");
        response.send("Nosto onnistui");
      } else {
        console.log("Something went wrong!");
        response.send("Nosto ei onnistunut");
      }
    }
  });
});

router.post('/deposit', 
function(request, response) {
  tili.deposit(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      if (dbResult["affectedRows"] > 0) { 
        console.log("Success!");
        response.send("Talletus onnistui");
      } else {
        console.log("Something went wrong!");
        response.send("Talletus ei onnistunut");
      }
    }
  });
});

module.exports = router;
