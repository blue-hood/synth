import 'core-js';
import 'regenerator-runtime/runtime';
import test from './test.clist';

const main = async () => {
  const { _test } = await test.initialize();

  document.body.innerHTML = String(_test());
};

main();
