const express = require('express');
const router = express.Router();
const kortti_tili = require('../models/kortti_tili_model');

router.get('/',
  function (request, response) {
    kortti_tili.getAll(function (err, dbResult) {
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
    kortti_tili.getById(request.params.id, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    })
  });


router.post('/',
  function (request, response) {
    kortti_tili.add(request.body, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(request.body);
      }
    });
  });


router.delete('/:id',
  function (request, response) {
    kortti_tili.delete(request.params.id, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  });


router.put('/:id',
  function (request, response) {
    kortti_tili.update(request.params.id, request.body, function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        response.json(dbResult);
      }
    });
  });
/////////////////////OMIA LISÄYKSIÄ/////////////////////////////

router.get('/showcredit',
  function (request, response) {
    kortti_tili.trueOrFalse(function (err, dbResult) {
      if (err) {
        response.json(err);
      } else {
        console.log(dbResult);
        response.json(dbResult);
      }
    })
  });
  



module.exports = router;
