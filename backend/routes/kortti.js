const express = require('express');
const router = express.Router();
const kortti = require('../models/kortti_model');

router.get('/',
    function (request, response) {
        kortti.getAll(function (err, dbResult) {
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
        kortti.getById(request.params.id, function (err, dbResult) {
            if (err) {
                response.json(err);
            } else {
                response.json(dbResult);
            }
        })
    });
    

router.post('/', 
function(request, response) {
  kortti.add(request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(request.body);
    }
  });
});


router.delete('/:id', 
function(request, response) {
  kortti.delete(request.params.id, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});


router.put('/:id', 
function(request, response) {
  kortti.update(request.params.id, request.body, function(err, dbResult) {
    if (err) {
      response.json(err);
    } else {
      response.json(dbResult);
    }
  });
});

//omia toimintoja
router.get('/asiakas/:id?',
function(request, response) {
 if (request.params.id) {
   kortti.getByCustomerId(request.params.id, function(err, dbResult) {
     if (err) {
       response.json(err);
     } else {
       response.json(dbResult[0]);
     }
   });
 }
});


//ainon judduja
router.put('/killcard/:id?',
function(request, response) {
 if (request.params.id) {
   kortti.putLockKortti(request.params.id, function(err, dbResult) {
     if (err) {
       response.json(err);
     } else {
       response.json(dbResult[0]);
     }
   });
 }
});

module.exports = router;