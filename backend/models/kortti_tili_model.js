const db = require('../database');

const tili_kortti = {
  getById: function(id, callback) {
    return db.query('select * from tili_kortti where id_tili_kortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili_kortti', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into tili_kortti (idtili_kortti,nimi,osoite,puh) values(?,?,?,?)',
      [add_data.idtili_kortti,add_data.nimi, add_data.osoite, add_data.puh],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili_kortti where id_tili_kortti=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update tili_kortti set nimi=?,osoite=?, puh=? where id_tili_kortti=?',
      [update_data.nimi, update_data.osoite, update_data.puh, id],
      callback
    );
  }
};
module.exports = tili_kortti;