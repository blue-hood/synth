/* eslint-disable @typescript-eslint/no-var-requires */
const CopyPlugin = require('copy-webpack-plugin');
const path = require('path');

module.exports = {
  module: {
    rules: [
      {
        test: /\.c(pp)?$/,
        type: 'javascript/auto',
        loader: '@wasm-tool/emscripten',
      },
      {
        test: /\.[jt]sx?$/,
        loader: 'babel-loader',
      },
    ],
  },
  node: {
    fs: 'empty',
  },
  optimization: {
    splitChunks: {
      chunks: 'all',
    },
  },
  output: {
    path: path.resolve(__dirname, 'dist'),
  },
  plugins: [new CopyPlugin([{ from: 'resources' }])],
  resolve: {
    extensions: ['.js', '.jsx', '.ts', '.tsx'],
  },
};
