const path = require('path')
const childProcess = require('child_process')
const { promisify } = require('util')

const { setTimeout } = require('timers')

const execFile = promisify(childProcess.execFile)

const yaml = require('js-yaml')

async function run(binPath) {
	const executableLocation = binPath || path.join(__dirname, 'GetForegroundWindow.exe')
	setInterval(async () => {
		try {
			const pyprocess = execFile(executableLocation)

			const output = await pyprocess

			let data = yaml.load(output.stdout.toString())

			console.log(data)
		} catch (error) {
			console.error(error)
		}
	}, 2000)
	// data.platform = 'windows';
	// data.name = data.name.toLowerCase();
	// data.app = data.name;

	// return data;
}

run()
