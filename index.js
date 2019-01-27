const addon = require('bindings')('n-api-stack-queue')

console.log(addon);
console.log(addon.hello());
console.log(addon.multiply(+'8', 5));

const { NapiQueue } = addon;

const queue = new NapiQueue();
console.dir(queue)

console.log(queue.enqueue(34234234234),
// queue.enqueue({ a: "test2" }),
// queue.enqueue({ a: "test3" })
)
const rc = queue.dequeue()
// const rb = queue.dequeue()
// const ra = queue.dequeue()

console.log(rc
  // , rb
  // , ra
  )
