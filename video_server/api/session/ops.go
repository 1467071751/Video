package session

import (
	"sync"
	"time"
	"video_server/api/dbops"
	"video_server/api/defs"
	"video_server/api/utils"
)

var sessionMap *sync.Map

func init() {
	sessionMap = &sync.Map{}
}

func deleteExpiredSession(sid string) {
	sessionMap.Delete(sid)
	dbops.DeleteSession(sid)
}

func LoadSessionsFromDB() {
	r, err := dbops.RetrieveAllSessions()
	if err != nil {
		return
	}

	r.Range(func(k, v interface{}) bool{
		ss := v.(*defs.SimpleSession)
		sessionMap.Store(k,ss)
		return true
	})
}

func GenerateNewSessionId(username string) string {
	id, _ := utils.NewUUID()
	ct := time.Now().UnixNano()/1000000
	ttl := ct + 30 * 60 * 1000

	ss := &defs.SimpleSession{Username: username, TTL: ttl}
	sessionMap.Store(id, ss)
	dbops.InsertSession(id, ttl, username)

	return id
}

func IsSessionExpired(sid string) (string, bool) {
	ss, ok := sessionMap.Load(sid)
	if ok {
		ct := time.Now().UnixNano()/1000000
		if ss.(*defs.SimpleSession).TTL < ct {
			deleteExpiredSession(sid)
			return "", true
		}

		return ss.(*defs.SimpleSession).Username, false
	}

	return "", true
}
