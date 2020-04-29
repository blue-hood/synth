import 'core-js';
import 'regenerator-runtime/runtime';

const main = async () => {
  const { _test } = await import('./test.cpp');

  document.body.innerHTML = String(_test());
};

main();
