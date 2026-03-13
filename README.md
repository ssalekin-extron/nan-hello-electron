# nan-hello-electron
Repo to reproduce v8 upgrade to 14.x and Electron 41.x.x bug in nan.

## Environment
```
node --version
v24.14.0

npm --version
11.9.0
``` 
OS: Windows 11
IDE/Compiler: Visual Studio 2022 v17.14
Win 10/11 SDK version: 10.0.26100.0

## Steps to Reproduce
1. Install dependencies
```
npm install
```
2. Build for Electron
```
npm run rebuild:electron
```
