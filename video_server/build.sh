#!/bin/bash

cd ~/goproject/src/video_server/web
go install
cp ~/goproject/bin/web ~/goproject/bin/video_server_web_ui/web
cp -R ~/goproject/src/video_server/templates ~/goproject/bin/video_server_web_ui/