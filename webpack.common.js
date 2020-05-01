/* eslint-disable @typescript-eslint/no-var-requires */
const CopyPlugin = require('copy-webpack-plugin');
const path = require('path');

module.exports = {
  module: {
    rules: [
      {
        test: /\.clist$/,
        use: [
          {
            loader: 'emcc-loader',
            options: {
              buildDir: `${__dirname}/dist`,
              commonFlags: ['-O2'],
              cFlags: ['-std=c11'],
              cxxFlags: ['-std=c++14'],
              ldFlags: [
                '-s', "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']",
                '-s', 'DEMANGLE_SUPPORT=1',
              ]
            }
          }
        ]
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
