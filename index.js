const addon = require('bindings')('n-api-stack-queue')

console.log(addon);
console.log(addon.hello());
console.log(addon.multiply(+'8', 5));

const { NapiQueue } = addon;

const queue = new NapiQueue();

console.log(queue.enqueue({ superKeyVal: "SuperValueKey"}),
)


console.log(queue.enqueue({ a: "test1" }))
queue.enqueue({ ad: "test3" })

const buffer = Buffer.from("ABC");

// synchronous, rotates each character by +13
// addon.rotate(buffer, buffer.length, 13);

// console.log(buffer.toString('ascii'));


  setTimeout(() => {
    const rc = queue.dequeue()
    const rb = queue.dequeue()
    const ra = queue.dequeue()

    console.log(rc
      , rb
      , ra
      )
    console.log('FINISH')
  }, 500);
