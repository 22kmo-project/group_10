const db = require('../database');


const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('select * from tilitapahtumat where idTilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilitapahtumat', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into tilitapahtumat (idTilitapahtumat,tilinumero,tilitapahtumat_pvm, selite,summa) values(?,?,?,?,?)',
      [add_data.idTilitapahtumat,add_data.tilinumero, add_data.tilitapahtumat_pvm, add_data.selite, add_data.summa],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where idTilitapahtumat=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update tilitapahtumat set tilinumero=?,tilitapahtumat_pvm=?, selite=?, summa=? where idTilitapahtumat=?',
      [update_data.tilinumero, update_data.tilitapahtumat_pvm, update_data.selite, update_data.summa, id],
      callback
    );
  }
};
module.exports = tilitapahtumat;