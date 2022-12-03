var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var asiakasRouter = require('./routes/asiakas');
var korttiRouter = require('./routes/kortti');
var tiliRouter = require('./routes/tili');
var kortti_tiliRouter = require('./routes/kortti_tili');
var tilitapahtumatRouter = require('./routes/tilitapahtumat');
var tilioikeudetRouter = require('./routes/tilioikeudet');

var app = express();

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use('/asiakas', asiakasRouter);
app.use('/kortti', korttiRouter);
app.use('/tili', tiliRouter);
app.use('/kortti_tili', kortti_tiliRouter);
app.use('/tilitapahtumat', tilitapahtumatRouter);
app.use('/tilioikeudet', tilioikeudetRouter);

module.exports = app;
