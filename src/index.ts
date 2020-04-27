import 'core-js';
import 'regenerator-runtime/runtime';

const main = async () => {
  const { _test } = await import('./test.c');

  document.body.innerHTML = String(_test(10));
};

main();
