const addon = require('bindings')('n-api-stack-queue')

console.log(addon);
console.log(addon.hello());
console.log(addon.multiply(+'8', 5));