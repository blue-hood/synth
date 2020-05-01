import 'core-js';
import 'regenerator-runtime/runtime';
import core from './core';

const main = async () => {
  const { _simulate } = await core.initialize();

  document.body.innerHTML = String(_simulate());
};

main();
