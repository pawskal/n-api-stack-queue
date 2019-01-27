const modBind = require('bindings')('n-api-stack-queue')
const modNode = require('./build/Release/n-api-stack-queue.node')

console.log(modBind, modNode);

console.log(modBind.hello());