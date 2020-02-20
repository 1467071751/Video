package taskrunner

const (
	READY_TO_DISPACH = "d"
	READY_TO_EXECUTE = "e"
	CLOSE = "c"

	VIDEO_PATH = "./home/xiamu/videos/"
)

type controlChan chan string

type dataChan chan interface{}

type fn func(dc dataChan) error
