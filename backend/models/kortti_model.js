const db = require('../database');

const kortti = {
  getById: function(id, callback) {
    return db.query('select * from kortti where id_kortti=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into kortti (idkortti,nimi,osoite,puh) values(?,?,?,?)',
      [add_data.idkortti,add_data.nimi, add_data.osoite, add_data.puh],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where id_kortti=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update kortti set nimi=?,osoite=?, puh=? where id_kortti=?',
      [update_data.nimi, update_data.osoite, update_data.puh, id],
      callback
    );
  }
};
module.exports = kortti;