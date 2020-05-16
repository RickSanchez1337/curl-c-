std::string Login(std::string key)
{
	CURL* curl = nullptr;
	CURLcode res;

	curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "index.php");
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "key=" + key);

		res = curl_easy_perform(curl);
		if (res != CURLE_OK)
			return "-";
		curl_easy_cleanup(curl);



	}
	curl_global_cleanup();

	//RE

	std::string response;
	std::string path = "index.php?key=" + key;


	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, path);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
		CURLcode code = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return response;


}
