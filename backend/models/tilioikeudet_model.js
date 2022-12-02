const db = require('../database');


const tilioikeudet = {
  getById: function(id, callback) {
    return db.query('select * from tilioikeudet where idTilioikeudet=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select * from tilioikeudet', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into tilioikeudet (idTilioikeudet,idTili,idAsiakas,omistaja) values(?,?,?,?)',
      [add_data.idTilioikeudet,add_data.idTili, add_data.idAsiakas, add_data.omistaja],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tilioikeudet where idTilioikeudet=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update tilioikeudet set idTili=?,idAsiakas=?, omistaja=? where idTilioikeudet=?',
      [update_data.idTili, update_data.idAsiakas, update_data.omistaja, id],
      callback
    );
  }
};
module.exports = tilioikeudet;