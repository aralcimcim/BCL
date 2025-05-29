from joblib import hash
from functools import wraps, cache


GLOBAL_ARRAYS_CACHE = {}


def np_cache(function):
    @cache
    def cached_wrapper(hashes):
        arrays = GLOBAL_ARRAYS_CACHE[hashes]
        return function(*arrays)

    @wraps(function)
    def wrapper(*arrays):
        hashes = tuple(hash(a) for a in arrays)
        GLOBAL_ARRAYS_CACHE[hashes] = arrays
        return cached_wrapper(hashes)

    wrapper.cache_info = cached_wrapper.cache_info
    wrapper.cache_clear = cached_wrapper.cache_clear

    return wrapper

def calc_pv_training_cache(function):
    @cache
    def cached_wrapper(hashes):
        arrays = GLOBAL_ARRAYS_CACHE[hashes]
        return function(*arrays)

    @wraps(function)
    def wrapper(*arrays):
        # arguments are `x, v, y, Z, sigmaU, sigmaV, phi, sigmaC, *args`
        # we only need to check y and Z
        hashes = tuple(hash(a) for a in arrays[2:4])
        GLOBAL_ARRAYS_CACHE[hashes] = arrays
        return cached_wrapper(hashes)

    wrapper.cache_info = cached_wrapper.cache_info
    wrapper.cache_clear = cached_wrapper.cache_clear

    return wrapper