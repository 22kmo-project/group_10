const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds=10;

const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where idKortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(add_data, callback) {
    bcrypt.hash(add_data.pin, saltRounds, function(err, hashedPassword){
    return db.query(
      'insert into kortti (idKortti,pin,idAsiakas) values(?,?,?)',
      [add_data.idKortti,hashedPassword, add_data.idAsiakas],
      callback)
    });
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where idKortti=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    bcrypt.hash(update_data.pin, saltRounds, function(err, hashedPassword){
    return db.query(      
      'update kortti set pin=?,idAsiakas=? where idKortti=?',
      [hashedPassword, update_data.idAsiakas, id],
      callback)
    });
  },
  checkPassword: function(idKortti, callback){
    return db.query('select pin from kortti where idKortti=?',[idKortti],callback);
  }
};
module.exports = kortti;