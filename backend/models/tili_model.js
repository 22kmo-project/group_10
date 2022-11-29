const db = require('../database');

const tili = {
  getById: function(id, callback) {
    return db.query('select * from tili where id_tili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into tili (idtili,nimi,osoite,puh) values(?,?,?,?)',
      [add_data.idtili,add_data.nimi, add_data.osoite, add_data.puh],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili where id_tili=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update tili set nimi=?,osoite=?, puh=? where id_tili=?',
      [update_data.nimi, update_data.osoite, update_data.puh, id],
      callback
    );
  }
};
module.exports = tili;