const db = require('../database');


const tilitapahtumat = {
  getById: function(id, callback) {
    return db.query('SELECT idTilitapahtumat, tilinumero, date_format(tilitapahtuma_pvm, "%d%m%Y") as "pvm", selite, summa FROM tilitapahtumat; where idTilitapahtumat=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('SELECT idTilitapahtumat, tilinumero, date_format(tilitapahtuma_pvm, "%d.%m.%Y") as "pvm", selite, summa FROM tilitapahtumat', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into tilitapahtumat (idTilitapahtumat,tilinumero,tilitapahtuma_pvm, selite,summa) values(?,?,?,?,?)',
      [add_data.idTilitapahtumat,add_data.tilinumero, add_data.tilitapahtuma_pvm, add_data.selite, add_data.summa],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilitapahtumat where idTilitapahtumat=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update tilitapahtumat set tilinumero=?,tilitapahtuma_pvm=?, selite=?, summa=? where idTilitapahtumat=?',
      [update_data.tilinumero, update_data.tilitapahtuma_pvm, update_data.selite, update_data.summa, id],
      callback
    );
  }
};
module.exports = tilitapahtumat;