const db = require('../database');

const asiakas = {
  getById: function(id, callback) {
    return db.query('select * from asiakas where idAsiakas=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from asiakas', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into asiakas (idAsiakas,nimi,osoite,puh) values(?,?,?,?)',
      [add_data.idAsiakas,add_data.nimi, add_data.osoite, add_data.puh],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from asiakas where idAsiakas=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update asiakas set nimi=?,osoite=?, puh=? where idAsiakas=?',
      [update_data.nimi, update_data.osoite, update_data.puh, id],
      callback
    );
  }
};
module.exports = asiakas;