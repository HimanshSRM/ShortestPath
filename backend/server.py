from flask import Flask, request, jsonify
import subprocess

app = Flask(__name__)

@app.route('/api/shortestpath', methods=['POST'])
def shortest_path():
    try:
        data = request.get_json()
        input_text = data.get('input', '')

        process = subprocess.Popen(
            ['singleSourceShortestPath.exe'],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        stdout, stderr = process.communicate(input=input_text)

        if process.returncode != 0:
            return jsonify({'error': stderr}), 500

        return jsonify({'result': stdout})

    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(port=5000)
