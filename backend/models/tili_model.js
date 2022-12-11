const db = require('../database');

const tili = {
  getById: function(id, callback) {
    return db.query('select * from tili where idTili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tili', callback);
  },
  getTenLatest: function(callback) {
    return db.query('select * from tili ORDER BY idTili LIMIT 10;', callback);
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
  },
  withdraw: function (data, callback) {
    return db.query('CALL nosto(?,?,?)', [data.id, data.tilinumTarkistus, data.haluttuSumma], callback);
  },
  deposit: function (data, callback) {
  return db.query('CALL talletus(?,?)', [data.tilinumTarkistus, data.talletettuSumma], callback);
  }
};

//Tästä alkaa muokattu
/*
withdraw: function (data, callback) {
  return db.query('CALL nosto(?,?,?)', [data.id,data.tilinumTarkistus, data.haluttuSumma], callback);
},
deposit: function (data, callback) {
return db.query('CALL talletus(?,?)', [data.tilinumTarkistus, data.talletettuSumma], callback);
},
};
*/
module.exports = tili;