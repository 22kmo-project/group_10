const express = require('express');
const router = express.Router();
const bcrypt = require('bcryptjs');
const kortti = require('../models/kortti_model');
const jwt = require('jsonwebtoken');
const dotenv = require('dotenv');

router.post('/', 
  function(request, response) {
    console.log("ID: " + request.body.idKortti +" PIN: "+ request.body.pin);
    if(request.body.idKortti && request.body.pin){
      const idKortti = request.body.idKortti;
      const pin = request.body.pin;
        kortti.checkPassword(idKortti, function(dbError, dbResult) {
          if(dbError){
            response.json(dbError);
          }
          else{
            if (dbResult.length > 0) {
              bcrypt.compare(pin,dbResult[0].pin, function(err,compareResult) {
                if(compareResult) {
                  console.log("Success");
                  const token = generateAccessToken({ username: idKortti });
                  response.send(token);
                }
                else {
                    console.log("Wrong password");
                    console.log(dbResult[0].pin);
                    response.send(false);
                }			
              }
              );
            }
            else{
              console.log("User does not exist");
              response.send(false);
            }
          }
          }
        );
      }
    else{
      console.log("idKortti or password missing");
      response.send(false);
    }
  }
);

function generateAccessToken(username) {
    dotenv.config();
    return jwt.sign(username, process.env.MY_TOKEN, { expiresIn: '1800s' });
  }
  

module.exports=router;