const db = require('../database');

const tili = {
  getById: function(id, callback) {
    return db.query('select * from tili where idTili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into tili (idTili,tilinumero,saldo) values(?,?,?)',
      [add_data.idTili,add_data.tilinumero, add_data.saldo],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tili where idTili=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update tili set tilinumero=?,saldo=? where idTili=?',
      [update_data.tilinumero, update_data.saldo, id],
      callback
    );
  }
};
module.exports = tili;