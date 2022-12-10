const db = require('../database');

const kortti_tili = {
  getById: function(id, callback) {
    return db.query('select idKortti_tili,idTili,idKortti, IF(credit, "true","false")credit from kortti_tili idKortti_tili=?', [id], callback);
  },
  getAll: function(callback) {
    return db.query('select idKortti_tili,idTili,idKortti, IF(credit, "true","false")credit from kortti_tili', callback);
  },
  add: function(add_data, callback) {
    return db.query(
      'insert into kortti_tili (idKortti_tili,idTili,idKortti) values(?,?,?)',
      [add_data.idKortti_tili,add_data.idTili, add_data.idKortti],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from kortti_tili where idKortti_tili=?', [id], callback);
  },
  update: function(id, update_data, callback) {
    return db.query(
      'update kortti_tili set idTili=?,idKortti=?, where idKortti_tili=?',
      [update_data.idTili, update_data.idKortti, id],
      callback
    );
  },
  /////////////////////OMIA LISÄYKSIÄ/////////////////////////////
  trueOrFalse: function(callback) {
    return db.query('select idKortti_tili,idTili,idKortti, IF(credit, "true","false")credit from kortti_tili;', [id], callback);
  },
};
module.exports = kortti_tili;